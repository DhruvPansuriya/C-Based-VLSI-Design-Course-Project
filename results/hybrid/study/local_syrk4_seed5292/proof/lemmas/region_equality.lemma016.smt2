; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x359492 (bvmul arg0_1 arg0_4)))
(let ((?x526645 (bvmul (_ bv4294967295 32) ?x359492)))
(let ((?x501260 (bvmul arg0_4 arg0_4)))
(let ((?x498335 (bvadd ?x501260 ?x526645)))
(and (distinct ?x498335 (_ bv0 32)) true))))))
(check-sat)
