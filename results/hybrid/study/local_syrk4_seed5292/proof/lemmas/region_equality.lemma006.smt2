; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x479396 (bvmul arg0_2 arg0_9)))
(let ((?x508882 (bvmul (_ bv4294967295 32) ?x479396)))
(let ((?x359359 (bvmul arg0_2 arg0_6)))
(let ((?x443447 (bvadd ?x359359 ?x508882)))
(and (distinct ?x443447 (_ bv0 32)) true))))))
(check-sat)
