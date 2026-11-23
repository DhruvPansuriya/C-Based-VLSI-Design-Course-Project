; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_37 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_44 () (_ BitVec 32))
(assert
 (let ((?x75226 (bvmul arg0_13 arg1_37)))
(let ((?x55256 (bvmul (_ bv4294967295 32) ?x75226)))
(let ((?x63768 (bvmul arg0_13 arg1_44)))
(let ((?x62821 (bvadd ?x63768 ?x55256)))
(and (distinct ?x62821 (_ bv0 32)) true))))))
(check-sat)
