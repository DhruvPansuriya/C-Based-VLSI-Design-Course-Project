; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_25 () (_ BitVec 32))
(assert
 (let ((?x75307 (bvmul arg0_3 arg1_11)))
(let ((?x61506 (bvmul (_ bv4294967295 32) ?x75307)))
(let ((?x63329 (bvmul arg0_3 arg1_25)))
(let ((?x68863 (bvadd ?x63329 ?x61506)))
(and (distinct ?x68863 (_ bv0 32)) true))))))
(check-sat)
