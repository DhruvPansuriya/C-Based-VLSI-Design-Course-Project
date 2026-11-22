<!-- version: 1 -->
## system
For each pointer or array parameter of the original function, propose the number of elements as an expression over the integer size parameters, using the request wording and the signature only. This is an informational cross-check against the caller profile.

Reply with a single JSON object {"buffers": {"<param>": "<size expression>"}, "rationale": "<one sentence>"} and nothing else.
## user
Original function signature: ${signature}
Request: ${request_text}
