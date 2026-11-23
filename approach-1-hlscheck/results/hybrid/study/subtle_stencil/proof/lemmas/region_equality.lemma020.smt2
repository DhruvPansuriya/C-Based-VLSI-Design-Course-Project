; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x334667 (bvmul arg0_16 arg2_3)))
(let ((?x391649 (bvmul (_ bv4294967295 32) ?x334667)))
(let ((?x336855 (bvmul arg0_16 arg2_4)))
(let ((?x736382 (bvadd ?x336855 ?x391649)))
(and (distinct ?x736382 (_ bv0 32)) true))))))
(check-sat)
