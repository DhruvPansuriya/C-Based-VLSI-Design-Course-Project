; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_2 () (_ BitVec 32))
(declare-fun arg0_14 () (_ BitVec 32))
(declare-fun arg1_8 () (_ BitVec 32))
(assert
 (let ((?x303392 (bvmul arg0_14 arg1_2)))
(let ((?x336164 (bvmul (_ bv4294967295 32) ?x303392)))
(let ((?x41296 (bvmul arg0_14 arg1_8)))
(let ((?x327718 (bvadd ?x41296 ?x336164)))
(and (distinct ?x327718 (_ bv0 32)) true))))))
(check-sat)
