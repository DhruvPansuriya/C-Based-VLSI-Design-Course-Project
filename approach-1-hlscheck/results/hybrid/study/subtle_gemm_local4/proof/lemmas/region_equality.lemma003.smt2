; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_10 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg1_11 () (_ BitVec 32))
(assert
 (let ((?x516026 (bvmul arg0_2 arg1_10)))
(let ((?x371599 (bvmul (_ bv4294967295 32) ?x516026)))
(let ((?x521674 (bvmul arg0_2 arg1_11)))
(let ((?x689848 (bvadd ?x521674 ?x371599)))
(and (distinct ?x689848 (_ bv0 32)) true))))))
(check-sat)
