; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_33 () (_ BitVec 32))
(declare-fun arg0_17 () (_ BitVec 32))
(declare-fun arg1_12 () (_ BitVec 32))
(assert
 (let ((?x23973 (bvmul arg0_17 arg1_33)))
(let ((?x58275 (bvmul (_ bv4294967295 32) ?x23973)))
(let ((?x63541 (bvmul arg0_17 arg1_12)))
(let ((?x69525 (bvadd ?x63541 ?x58275)))
(and (distinct ?x69525 (_ bv0 32)) true))))))
(check-sat)
