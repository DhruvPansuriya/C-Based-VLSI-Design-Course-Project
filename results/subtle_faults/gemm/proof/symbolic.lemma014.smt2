; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x158 (bvmul arg0_6 arg1_2)))
(let ((?x15160 (bvmul (_ bv4294967295 32) ?x158)))
(let ((?x107 (bvmul arg0_6 arg1_8)))
(let ((?x19520 (bvadd ?x107 ?x15160)))
(and (distinct ?x19520 (_ bv0 32)) true))))))
(check-sat)
