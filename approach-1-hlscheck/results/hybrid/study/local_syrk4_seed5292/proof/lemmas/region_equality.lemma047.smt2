; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(assert
 (let ((?x377189 (bvmul arg0_12 arg0_3)))
(let ((?x12110 (bvmul (_ bv4294967295 32) ?x377189)))
(let ((?x417326 (bvmul arg0_12 arg0_12)))
(let ((?x516891 (bvadd ?x417326 ?x12110)))
(and (distinct ?x516891 (_ bv0 32)) true))))))
(check-sat)
