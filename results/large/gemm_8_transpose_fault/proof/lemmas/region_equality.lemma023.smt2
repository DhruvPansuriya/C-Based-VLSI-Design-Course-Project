; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_25 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x73083 (bvmul arg0_1 arg1_25)))
(let ((?x65634 (bvmul (_ bv4294967295 32) ?x73083)))
(let ((?x63379 (bvmul arg0_1 arg1_11)))
(let ((?x65310 (bvadd ?x63379 ?x65634)))
(and (distinct ?x65310 (_ bv0 32)) true))))))
(check-sat)
