; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(assert
 (let ((?x770 (bvmul arg0_2 arg0_8)))
(let ((?x122 (bvmul (_ bv4294967295 32) ?x770)))
(let ((?x409 (bvmul arg0_2 arg0_2)))
(let ((?x26824 (bvadd ?x409 ?x122)))
(and (distinct ?x26824 (_ bv0 32)) true))))))
(check-sat)
