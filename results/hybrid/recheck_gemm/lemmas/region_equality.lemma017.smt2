; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x154 (bvmul arg0_6 arg1_6)))
(let ((?x3039 (bvmul (_ bv4294967295 32) ?x154)))
(let ((?x81 (bvmul arg0_6 arg1_9)))
(let ((?x213 (bvadd ?x81 ?x3039)))
(and (distinct ?x213 (_ bv0 32)) true))))))
(check-sat)
