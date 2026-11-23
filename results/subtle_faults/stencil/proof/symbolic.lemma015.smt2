; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x15350 (bvmul arg0_7 arg2_0)))
(let ((?x79 (bvmul (_ bv4294967295 32) ?x15350)))
(let ((?x119 (bvmul arg0_7 arg2_1)))
(let ((?x711888 (bvadd ?x119 ?x79)))
(and (distinct ?x711888 (_ bv0 32)) true))))))
(check-sat)
