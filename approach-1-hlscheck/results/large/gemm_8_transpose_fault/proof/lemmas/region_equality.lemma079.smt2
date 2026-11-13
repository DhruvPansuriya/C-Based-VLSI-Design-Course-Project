; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_28 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_35 () (_ BitVec 32))
(assert
 (let ((?x64113 (bvmul arg0_12 arg1_28)))
(let ((?x70373 (bvmul (_ bv4294967295 32) ?x64113)))
(let ((?x63879 (bvmul arg0_12 arg1_35)))
(let ((?x68471 (bvadd ?x63879 ?x70373)))
(and (distinct ?x68471 (_ bv0 32)) true))))))
(check-sat)
