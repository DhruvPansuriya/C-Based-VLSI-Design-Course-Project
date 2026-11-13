; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x210 (bvmul arg0_14 arg1_2)))
(let ((?x16864 (bvmul (_ bv4294967295 32) ?x210)))
(let ((?x104 (bvmul arg0_14 arg1_8)))
(let ((?x18337 (bvadd ?x104 ?x16864)))
(and (distinct ?x18337 (_ bv0 32)) true))))))
(check-sat)
