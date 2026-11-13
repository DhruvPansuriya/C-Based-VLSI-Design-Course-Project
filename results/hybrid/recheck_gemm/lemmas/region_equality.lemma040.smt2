; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x180 (bvmul arg0_12 arg1_4)))
(let ((?x849 (bvmul (_ bv4294967295 32) ?x180)))
(let ((?x117 (bvmul arg0_12 arg1_1)))
(let ((?x13045 (bvadd ?x117 ?x849)))
(and (distinct ?x13045 (_ bv0 32)) true))))))
(check-sat)
