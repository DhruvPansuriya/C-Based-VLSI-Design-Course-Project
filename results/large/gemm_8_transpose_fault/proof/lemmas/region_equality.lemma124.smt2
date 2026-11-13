; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_41 () (_ BitVec 32))
(assert
 (let ((?x8755 (bvmul arg0_21 arg1_13)))
(let ((?x66967 (bvmul (_ bv4294967295 32) ?x8755)))
(let ((?x16492 (bvmul arg0_21 arg1_41)))
(let ((?x66124 (bvadd ?x16492 ?x66967)))
(and (distinct ?x66124 (_ bv0 32)) true))))))
(check-sat)
