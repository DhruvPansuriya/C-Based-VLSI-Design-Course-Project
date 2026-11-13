; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_19 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_26 () (_ BitVec 32))
(assert
 (let ((?x75210 (bvmul arg0_19 arg1_19)))
(let ((?x53658 (bvmul (_ bv4294967295 32) ?x75210)))
(let ((?x63646 (bvmul arg0_19 arg1_26)))
(let ((?x70522 (bvadd ?x63646 ?x53658)))
(and (distinct ?x70522 (_ bv0 32)) true))))))
(check-sat)
