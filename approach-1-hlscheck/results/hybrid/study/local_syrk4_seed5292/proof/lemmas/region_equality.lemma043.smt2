; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(assert
 (let ((?x445524 (bvmul arg0_12 arg0_2)))
(let ((?x2792 (bvmul (_ bv4294967295 32) ?x445524)))
(let ((?x485029 (bvmul arg0_12 arg0_8)))
(let ((?x362075 (bvadd ?x485029 ?x2792)))
(and (distinct ?x362075 (_ bv0 32)) true))))))
(check-sat)
