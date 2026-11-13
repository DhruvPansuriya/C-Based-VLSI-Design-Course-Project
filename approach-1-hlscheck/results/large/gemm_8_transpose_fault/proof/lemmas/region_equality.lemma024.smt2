; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_26 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_19 () (_ BitVec 32))
(assert
 (let ((?x75316 (bvmul arg0_2 arg1_26)))
(let ((?x55170 (bvmul (_ bv4294967295 32) ?x75316)))
(let ((?x63523 (bvmul arg0_2 arg1_19)))
(let ((?x60820 (bvadd ?x63523 ?x55170)))
(and (distinct ?x60820 (_ bv0 32)) true))))))
(check-sat)
