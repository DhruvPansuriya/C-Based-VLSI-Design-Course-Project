; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_16 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_2 () (_ BitVec 32))
(assert
 (let ((?x73092 (bvmul arg0_0 arg1_16)))
(let ((?x24935 (bvmul (_ bv4294967295 32) ?x73092)))
(let ((?x63328 (bvmul arg0_0 arg1_2)))
(let ((?x68223 (bvadd ?x63328 ?x24935)))
(and (distinct ?x68223 (_ bv0 32)) true))))))
(check-sat)
