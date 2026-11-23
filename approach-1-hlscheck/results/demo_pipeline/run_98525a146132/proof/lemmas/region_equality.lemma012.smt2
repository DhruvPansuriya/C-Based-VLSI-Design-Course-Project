; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul (_ bv4294967295 32) arg1_6)))
(let ((?x156 (bvmul (_ bv4294967295 32) arg0_1)))
(let ((?x63 (bvmul arg0_1 arg1_6)))
(let ((?x254 (bvadd ?x63 ?x156 ?x180)))
(and (distinct ?x254 (_ bv0 32)) true))))))
(check-sat)
