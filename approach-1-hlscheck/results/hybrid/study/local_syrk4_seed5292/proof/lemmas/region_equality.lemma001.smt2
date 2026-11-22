; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x359492 (bvmul arg0_1 arg0_4)))
(let ((?x526645 (bvmul (_ bv4294967295 32) ?x359492)))
(let ((?x417610 (bvmul arg0_1 arg0_1)))
(let ((?x512414 (bvadd ?x417610 ?x526645)))
(and (distinct ?x512414 (_ bv0 32)) true))))))
(check-sat)
