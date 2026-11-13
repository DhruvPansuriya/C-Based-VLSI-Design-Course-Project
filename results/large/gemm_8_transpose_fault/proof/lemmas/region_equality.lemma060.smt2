; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_5 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_40 () (_ BitVec 32))
(assert
 (let ((?x70878 (bvmul arg0_13 arg1_5)))
(let ((?x69612 (bvmul (_ bv4294967295 32) ?x70878)))
(let ((?x6575 (bvmul arg0_13 arg1_40)))
(let ((?x66979 (bvadd ?x6575 ?x69612)))
(and (distinct ?x66979 (_ bv0 32)) true))))))
(check-sat)
