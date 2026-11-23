; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_33 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x75313 (bvmul arg0_1 arg1_33)))
(let ((?x69958 (bvmul (_ bv4294967295 32) ?x75313)))
(let ((?x63625 (bvmul arg0_1 arg1_12)))
(let ((?x70788 (bvadd ?x63625 ?x69958)))
(and (distinct ?x70788 (_ bv0 32)) true))))))
(check-sat)
