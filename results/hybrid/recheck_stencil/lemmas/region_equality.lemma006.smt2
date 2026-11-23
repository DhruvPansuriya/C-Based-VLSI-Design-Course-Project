; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x10 (bvmul arg0_7 arg2_5)))
(let ((?x7775 (bvmul (_ bv4294967295 32) ?x10)))
(let ((?x16677 (bvmul arg0_7 arg2_4)))
(let ((?x196 (bvadd ?x16677 ?x7775)))
(and (distinct ?x196 (_ bv0 32)) true))))))
(check-sat)
