; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x1084 (bvmul arg0_2 arg0_4)))
(let ((?x29634 (bvmul (_ bv4294967295 32) ?x1084)))
(let ((?x82 (bvmul arg0_4 arg0_8)))
(let ((?x25371 (bvadd ?x82 ?x29634)))
(and (distinct ?x25371 (_ bv0 32)) true))))))
(check-sat)
