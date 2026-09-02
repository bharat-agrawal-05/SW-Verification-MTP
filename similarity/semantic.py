"""Semantic Similarity (S_semantic) computation using Sentence Transformers / BERT embeddings."""

from typing import List, Optional
import numpy as np
from core.problem import Problem


class SemanticSimilarity:
    """Computes S_semantic between two Loop Invariant problems P and Q as described in Section IV-C2(a)."""

    def __init__(self, model_name: str = "all-MiniLM-L6-v2"):
        self.model_name = model_name
        self._model = None

    def _load_model(self):
        if self._model is None:
            try:
                from sentence_transformers import SentenceTransformer
                self._model = SentenceTransformer(self.model_name)
            except Exception:
                self._model = None

    def _problem_to_text(self, p: Problem) -> str:
        """Converts problem specification into clean text representation for embedding."""
        return f"Precondition: {p.pre_f} Transition: {p.trans_f} Postcondition: {p.post_f}"

    def compute(self, p: Problem, q: Problem) -> float:
        """Computes cosine similarity between problem embeddings."""
        self._load_model()
        text_p = self._problem_to_text(p)
        text_q = self._problem_to_text(q)

        if self._model is not None:
            try:
                embeddings = self._model.encode([text_p, text_q], convert_to_numpy=True)
                emb1, emb2 = embeddings[0], embeddings[1]
                norm1 = np.linalg.norm(emb1)
                norm2 = np.linalg.norm(emb2)
                if norm1 == 0 or norm2 == 0:
                    return 0.0
                cos_sim = float(np.dot(emb1, emb2) / (norm1 * norm2))
                return max(0.0, min(1.0, cos_sim))
            except Exception:
                pass

        # Fallback word-overlap Jaccard similarity if transformer is not loaded
        tokens_p = set(text_p.split())
        tokens_q = set(text_q.split())
        if not tokens_p or not tokens_q:
            return 0.0
        return len(tokens_p & tokens_q) / len(tokens_p | tokens_q)
