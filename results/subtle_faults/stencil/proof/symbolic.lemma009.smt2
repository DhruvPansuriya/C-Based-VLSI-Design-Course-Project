; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x181 (bvmul arg0_8 arg2_3)))
(let ((?x33 (bvmul (_ bv4294967295 32) ?x181)))
(let ((?x711015 (bvmul arg0_8 arg2_4)))
(let ((?x333892 (bvadd ?x711015 ?x33)))
(and (distinct ?x333892 (_ bv0 32)) true))))))
(check-sat)
