; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_6 () (_ BitVec 32))
(declare-fun arg0_23 () (_ BitVec 32))
(declare-fun arg2_7 () (_ BitVec 32))
(assert
 (let ((?x308 (bvmul arg0_23 arg2_6)))
(let ((?x723854 (bvmul (_ bv4294967295 32) ?x308)))
(let ((?x175 (bvmul arg0_23 arg2_7)))
(let ((?x730023 (bvadd ?x175 ?x723854)))
(and (distinct ?x730023 (_ bv0 32)) true))))))
(check-sat)
