; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_61 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_47 () (_ BitVec 32))
(assert
 (let ((?x75230 (bvmul arg0_13 arg1_61)))
(let ((?x64216 (bvmul (_ bv4294967295 32) ?x75230)))
(let ((?x63797 (bvmul arg0_13 arg1_47)))
(let ((?x62137 (bvadd ?x63797 ?x64216)))
(and (distinct ?x62137 (_ bv0 32)) true))))))
(check-sat)
