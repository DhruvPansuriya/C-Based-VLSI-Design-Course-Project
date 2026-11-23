; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x42 (bvmul arg0_4 arg1_8)))
(let ((?x10920 (bvmul (_ bv4294967295 32) ?x42)))
(let ((?x140 (bvmul arg0_4 arg1_2)))
(let ((?x13902 (bvadd ?x140 ?x10920)))
(and (distinct ?x13902 (_ bv0 32)) true))))))
(check-sat)
