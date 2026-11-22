; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x332432 (bvmul arg0_8 arg2_0)))
(let ((?x660163 (bvmul (_ bv4294967295 32) ?x332432)))
(let ((?x361917 (bvmul arg0_8 arg2_1)))
(let ((?x517000 (bvadd ?x361917 ?x660163)))
(and (distinct ?x517000 (_ bv0 32)) true))))))
(check-sat)
