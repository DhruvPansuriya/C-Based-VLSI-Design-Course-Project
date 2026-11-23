; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x171 (bvmul (_ bv4294967295 32) arg1_10)))
(let ((?x157 (bvmul (_ bv4294967295 32) arg0_2)))
(let ((?x67 (bvmul arg0_2 arg1_10)))
(let ((?x173 (bvadd ?x67 ?x157 ?x171)))
(and (distinct ?x173 (_ bv0 32)) true))))))
(check-sat)
