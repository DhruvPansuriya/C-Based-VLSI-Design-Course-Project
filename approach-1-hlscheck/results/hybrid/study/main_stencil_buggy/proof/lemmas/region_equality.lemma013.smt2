; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x64 (bvmul arg0_12 arg2_5)))
(let ((?x8312 (bvmul (_ bv4294967295 32) ?x64)))
(let ((?x21260 (bvmul arg0_12 arg2_4)))
(let ((?x725326 (bvadd ?x21260 ?x8312)))
(and (distinct ?x725326 (_ bv0 32)) true))))))
(check-sat)
