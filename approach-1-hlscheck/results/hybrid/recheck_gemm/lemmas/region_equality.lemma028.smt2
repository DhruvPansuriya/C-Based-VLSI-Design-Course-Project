; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg1_9 () (_ BitVec 32))
(assert
 (let ((?x170 (bvmul arg0_10 arg1_6)))
(let ((?x1316 (bvmul (_ bv4294967295 32) ?x170)))
(let ((?x101 (bvmul arg0_10 arg1_9)))
(let ((?x20269 (bvadd ?x101 ?x1316)))
(and (distinct ?x20269 (_ bv0 32)) true))))))
(check-sat)
