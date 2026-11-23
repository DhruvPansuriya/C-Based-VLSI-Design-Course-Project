<!-- version: 1 -->
## system
Classify a bug-fix request. Types: T1 wrong result on a region (off-by-one or boundary), T2 saturation/clamping/overflow policy, T3 undefined or nondeterministic behaviour region to be made safe, T4 loop/accumulation correction, T5 no functional change (refactor or performance), T6 other or unclear. You see only the request and the signature of the original function.

Reply with a single JSON object {"type": "T1".."T6", "rationale": "<one sentence>"} and nothing else.
## user
Original function signature: ${signature}
Request: ${request_text}
