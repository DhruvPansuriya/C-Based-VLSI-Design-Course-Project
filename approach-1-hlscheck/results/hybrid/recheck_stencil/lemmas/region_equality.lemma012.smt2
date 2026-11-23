; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x19109 (bvmul arg0_6 arg2_2)))
(let ((?x94924 (bvmul (_ bv4294967295 32) ?x19109)))
(let ((?x145 (bvmul arg0_6 arg2_1)))
(let ((?x711424 (bvadd ?x145 ?x94924)))
(and (distinct ?x711424 (_ bv0 32)) true))))))
(check-sat)
