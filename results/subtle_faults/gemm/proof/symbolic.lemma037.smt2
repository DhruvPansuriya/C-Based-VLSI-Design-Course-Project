; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_4 () (_ BitVec 32))
(assert
 (let ((?x190 (bvmul arg0_13 arg1_1)))
(let ((?x308 (bvmul (_ bv4294967295 32) ?x190)))
(let ((?x100 (bvmul arg0_13 arg1_4)))
(let ((?x12431 (bvadd ?x100 ?x308)))
(and (distinct ?x12431 (_ bv0 32)) true))))))
(check-sat)
