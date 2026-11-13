; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_38 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_52 () (_ BitVec 32))
(assert
 (let ((?x39416 (bvmul arg0_14 arg1_38)))
(let ((?x69540 (bvmul (_ bv4294967295 32) ?x39416)))
(let ((?x2753 (bvmul arg0_14 arg1_52)))
(let ((?x59166 (bvadd ?x2753 ?x69540)))
(and (distinct ?x59166 (_ bv0 32)) true))))))
(check-sat)
