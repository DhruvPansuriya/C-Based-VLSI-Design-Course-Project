; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_5 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x116 (bvmul arg0_16 arg2_5)))
(let ((?x710421 (bvmul (_ bv4294967295 32) ?x116)))
(let ((?x18724 (bvmul arg0_16 arg2_4)))
(let ((?x720077 (bvadd ?x18724 ?x710421)))
(and (distinct ?x720077 (_ bv0 32)) true))))))
(check-sat)
