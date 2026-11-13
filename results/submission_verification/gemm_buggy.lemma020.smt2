; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_9 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x9 (bvmul arg0_5 arg1_9)))
(let ((?x8589 (bvmul (_ bv4294967295 32) ?x9)))
(let ((?x173 (bvmul arg0_5 arg1_6)))
(let ((?x9035 (bvadd ?x173 ?x8589)))
(and (distinct ?x9035 (_ bv0 32)) true))))))
(check-sat)
