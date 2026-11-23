; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_19 () (_ BitVec 32))
(declare-fun arg0_27 () (_ BitVec 32))
(declare-fun arg1_26 () (_ BitVec 32))
(assert
 (let ((?x63951 (bvmul arg0_27 arg1_19)))
(let ((?x58200 (bvmul (_ bv4294967295 32) ?x63951)))
(let ((?x12445 (bvmul arg0_27 arg1_26)))
(let ((?x54464 (bvadd ?x12445 ?x58200)))
(and (distinct ?x54464 (_ bv0 32)) true))))))
(check-sat)
