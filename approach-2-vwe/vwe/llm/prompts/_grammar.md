CONTRACT EXPRESSION LANGUAGE (all expressions are strings in this restricted C-like language)
- Integer and boolean expressions with the C operators: + - * / % << >> & | ^ ~ ! && || == != < <= > >= and ?:
- Helpers: min(x, y), max(x, y), abs(x). Constants: INT_MIN, INT_MAX, UINT_MAX, UINT8_MAX, INT8_MIN, INT8_MAX, INT16_MIN, INT16_MAX, UINT16_MAX.
- Parameters keep their names. For the function result use out_ret; for pointer or array parameter p use out_p[i] after the call and old_p[i] for the ORIGINAL buggy function's result (old_ret, old_p[i]). Input values before the call use the bare parameter name.
- Bounded reductions: forall(i, lo, hi, body), exists(i, lo, hi, body), sum(i, lo, hi, body), count(i, lo, hi, body) range over lo <= i < hi.
- A clause has a zone (a predicate over INPUTS only) and a behaviour (relation over inputs and out_/old_ names): inside the zone the repaired function must satisfy the behaviour.
- ext is the behaviour required OUTSIDE every zone (usually "unchanged from the original": out_ret == old_ret and the same for each output), or the string "unknown" if the request does not determine it.
- reach is the largest input region the change could reasonably affect; use "unknown" only if the request gives no hint.
- Never invent identifiers. Do not call C library functions. No casts, no assignments, no pointers arithmetic.
