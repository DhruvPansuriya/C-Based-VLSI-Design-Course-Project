; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x674015 (bvmul arg0_5 arg1_6)))
(let ((?x367344 (bvmul (_ bv4294967295 32) ?x674015)))
(let ((?x386791 (bvmul arg0_5 arg1_7)))
(let ((?x406194 (bvadd ?x386791 ?x367344)))
(and (distinct ?x406194 (_ bv0 32)) true))))))
(check-sat)
