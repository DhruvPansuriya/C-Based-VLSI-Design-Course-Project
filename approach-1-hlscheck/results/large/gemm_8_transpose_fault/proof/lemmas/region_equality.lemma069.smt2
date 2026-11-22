; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_15 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_57 () (_ BitVec 32))
(assert
 (let ((?x39421 (bvmul arg0_15 arg1_15)))
(let ((?x61687 (bvmul (_ bv4294967295 32) ?x39421)))
(let ((?x63779 (bvmul arg0_15 arg1_57)))
(let ((?x65716 (bvadd ?x63779 ?x61687)))
(and (distinct ?x65716 (_ bv0 32)) true))))))
(check-sat)
