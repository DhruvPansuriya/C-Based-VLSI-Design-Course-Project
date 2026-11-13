; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x186 (bvmul arg0_8 arg2_0)))
(let ((?x711132 (bvmul (_ bv4294967295 32) ?x186)))
(let ((?x21910 (bvmul arg0_8 arg2_1)))
(let ((?x713340 (bvadd ?x21910 ?x711132)))
(and (distinct ?x713340 (_ bv0 32)) true))))))
(check-sat)
