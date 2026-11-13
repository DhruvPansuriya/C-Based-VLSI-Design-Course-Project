; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_20 () (_ BitVec 32))
(declare-fun arg1_33 () (_ BitVec 32))
(assert
 (let ((?x75202 (bvmul arg0_20 arg1_12)))
(let ((?x65644 (bvmul (_ bv4294967295 32) ?x75202)))
(let ((?x63382 (bvmul arg0_20 arg1_33)))
(let ((?x69366 (bvadd ?x63382 ?x65644)))
(and (distinct ?x69366 (_ bv0 32)) true))))))
(check-sat)
