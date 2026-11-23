; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(assert
 (let ((?x417710 (bvmul arg0_4 arg0_5)))
(let ((?x429536 (bvmul (_ bv4294967295 32) ?x417710)))
(let ((?x361917 (bvmul arg0_1 arg0_5)))
(let ((?x493234 (bvadd ?x361917 ?x429536)))
(and (distinct ?x493234 (_ bv0 32)) true))))))
(check-sat)
