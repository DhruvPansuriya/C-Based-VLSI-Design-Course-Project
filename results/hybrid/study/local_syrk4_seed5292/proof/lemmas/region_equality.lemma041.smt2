; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x510165 (bvmul arg0_13 arg0_15)))
(let ((?x464490 (bvmul (_ bv4294967295 32) ?x510165)))
(let ((?x416056 (bvmul arg0_15 arg0_7)))
(let ((?x364852 (bvadd ?x416056 ?x464490)))
(and (distinct ?x364852 (_ bv0 32)) true))))))
(check-sat)
