; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_30 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_51 () (_ BitVec 32))
(assert
 (let ((?x75237 (bvmul arg0_14 arg1_30)))
(let ((?x69771 (bvmul (_ bv4294967295 32) ?x75237)))
(let ((?x64035 (bvmul arg0_14 arg1_51)))
(let ((?x64216 (bvadd ?x64035 ?x69771)))
(and (distinct ?x64216 (_ bv0 32)) true))))))
(check-sat)
