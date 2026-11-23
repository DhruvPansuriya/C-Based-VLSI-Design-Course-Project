; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_19 () (_ BitVec 32))
(declare-fun arg1_25 () (_ BitVec 32))
(assert
 (let ((?x72913 (bvmul arg0_19 arg1_11)))
(let ((?x60739 (bvmul (_ bv4294967295 32) ?x72913)))
(let ((?x63554 (bvmul arg0_19 arg1_25)))
(let ((?x70733 (bvadd ?x63554 ?x60739)))
(and (distinct ?x70733 (_ bv0 32)) true))))))
(check-sat)
