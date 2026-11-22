WORKED EXAMPLES (invented tasks, unrelated to any evaluation task)

Example A. Signature: int clamp_low(int x, int lo); Request: "Values below lo should be raised to lo; other values must stay as they are."
{"id": "example_a", "provenance": {"source": "llm"}, "request_type": "T2",
 "shape": {"buffers": {}, "alias": "disjoint", "bounds": {}},
 "clauses": [{"zone": "x < lo", "behaviour": "out_ret == lo"}],
 "ext": "out_ret == old_ret", "reach": "x < lo",
 "nl_rendering": "When x is below lo return lo; otherwise behave exactly as before."}

Example B. Signature: int count_pos(const int *v, int len); Request: "It skips the last element; count positives in all len entries."
{"id": "example_b", "provenance": {"source": "llm"}, "request_type": "T1",
 "shape": {"buffers": {"v": "len"}, "alias": "disjoint", "bounds": {"len": [0, 4]}},
 "clauses": [{"zone": "len >= 1", "behaviour": "out_ret == count(i, 0, len, v[i] > 0)"}],
 "ext": "out_ret == old_ret", "reach": "len >= 1",
 "nl_rendering": "For every nonempty array count the positive entries across all len elements."}
